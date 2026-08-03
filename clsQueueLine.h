#pragma once
#include "clsDate.h"
#include "clsUtil.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class clsQueueLine
{
private:
	short _totalTickets = 0;
	short _averageServeTime = 0;
	string _prefix = "";

	class clsTicket
	{


	private:
		short _TicketNumber = 0;
		string _Prefix = "";
		string _IssueTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectedServeTime = 0;


	public:
		clsTicket(string Prefix, short TicketNumber, short WaitingClients, short AverageServeTime)
		{
			_TicketNumber = TicketNumber;
			_Prefix = Prefix;
			_IssueTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;

		};

		const string& Prefix() const { return _Prefix; }
		const short& Number() const { return _TicketNumber; }
		string FullNumber() const { return _Prefix + to_string(_TicketNumber); }
		const string& IssueTime() const { return _IssueTime; }
		const short& WaitingClients() const { return _WaitingClients; }
		short ExpectedServeTime() const { return _AverageServeTime * _WaitingClients; }


		void Print()
		{
			string separatorLine = clsUtil::ColorText("_______________________________________\n", clsUtil::enColor::BRIGHT_MAGENTA);

			cout << Spaces(40) << separatorLine;
			cout << Spaces(40) << "\t\t" << FullNumber() << '\n';
			cout << Spaces(40) << "\t" << IssueTime() << '\n';
			cout << Spaces(40) << "\tWaiting Clients = " << WaitingClients() << '\n';
			cout << Spaces(40) << "\tServe Time In " << ExpectedServeTime() << " Minutes.\n";
			cout << Spaces(40) << separatorLine;

			cout << endl;
		}

	};


	static string Spaces(short count = 37)
	{
		return std::string(count, ' ');
	}

	queue<clsTicket> _QueueLine;
public:


	clsQueueLine(const string& prefix, int averageServeTime) : _prefix(prefix), _averageServeTime(averageServeTime)
	{
		_totalTickets = 0;
	}



	void IssueTicket()
	{
		_totalTickets++;
		clsTicket ticket(_prefix, _totalTickets, WaitingClients(), _averageServeTime);
		_QueueLine.push(ticket);
	}

	int WaitingClients() const
	{
		return _QueueLine.size();
	}
	short ServedClients() const
	{
		return _totalTickets - WaitingClients();
	}


	void PrintInfo()
	{

		string separatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t\t\tQueue Info\n";
		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t Prefix          = " << _prefix << '\n';
		cout << Spaces() << "\t Total Tickets   = " << _totalTickets << '\n';
		cout << Spaces() << "\t Served Clients  = " << ServedClients() << '\n';
		cout << Spaces() << "\t Waiting Clients = " << WaitingClients() << '\n';
		cout << Spaces() << separatorLine << endl;

	}

	void PrintTicketsLineRTL() const
	{
		string rArrow = clsUtil::ColorText(" <-- ", clsUtil::enColor::BRIGHT_GREEN);

		if (_QueueLine.empty()) cout << Spaces() << " Tickets: No Tickets... ";
		else cout << Spaces(30) << " Tickets: ";

		queue <clsTicket> tempQueueLine = _QueueLine;

		while (!tempQueueLine.empty())
		{
			clsTicket ticket = tempQueueLine.front();

			cout << " " << ticket.FullNumber() << rArrow;

			tempQueueLine.pop();
		}
		cout << endl;

	}

	void PrintTicketsLineLTR() const
	{
		string lArrow = clsUtil::ColorText(" --> ", clsUtil::enColor::BRIGHT_GREEN);

		if (_QueueLine.empty()) cout << Spaces() << " Tickets: No Tickets... ";
		else cout << Spaces(30) << " Tickets: ";

		queue <clsTicket> tempQueueLine = _QueueLine;
		stack <clsTicket> tempStackLine;

		while (!tempQueueLine.empty())
		{
			tempStackLine.push(tempQueueLine.front());
			tempQueueLine.pop();
		}

		while (!tempStackLine.empty())
		{
			clsTicket ticket = tempStackLine.top();

			cout << " " << ticket.FullNumber() << lArrow;

			tempStackLine.pop();
		}
		cout << endl;



	}

	void PrintAllTickets()
	{
		string TicketsTitle = clsUtil::ColorText("\t\t     ---Tickets---\n", clsUtil::enColor::BRIGHT_GREEN);
		string NoTickets = clsUtil::ColorText("\t\t   ---No Tickets---\n", clsUtil::enColor::BRIGHT_RED);

		cout << endl << Spaces(35) << TicketsTitle;
		if (_QueueLine.empty()) cout << endl << Spaces(35) << NoTickets;

		queue<clsTicket> tempQ = _QueueLine;

		while (!tempQ.empty())
		{
			tempQ.front().Print();
			tempQ.pop();
		}

	}


	bool ServeNextClient()
	{
		if (_QueueLine.empty()) return false;

		_QueueLine.pop();
		return true;

	}

	string WhoIsNext() const
	{
		if (_QueueLine.empty()) return "No Clients";
		return (_QueueLine.front().FullNumber());
	}

};

