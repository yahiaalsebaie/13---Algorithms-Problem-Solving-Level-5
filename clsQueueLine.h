#pragma once
#include "clsDate.h"
#include "clsMyQueue.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

using namespace std;

class clsQueueLine
{
private:
	struct stTicket
	{
		int TicketNumber = 0;
		string IssueTime;
		int ExpectedServeTime = 0;
	};

	clsMyQueue<stTicket> _queue;

	string _prefix = "";
	int _operationTime = 0;
	int _totalTickets = 0;
	int _servedClients = 0;


private:

	int GetWaitingClients() const
	{
		return _totalTickets - _servedClients ;
	}
	static string Spaces(short count = 37)
	{
		return std::string(count, ' ');
	}

public:

	/*clsQueueLine(const std::string& prefix, int OpTime)
	{
		_prefix = prefix;
		_operationTime = OpTime;
	}*/
	clsQueueLine(const string& prefix, int operationTime) : _prefix(prefix), _operationTime(operationTime){ }

	
	
	void IssueTicket()
	{
		stTicket ticket;

		ticket.TicketNumber = ++_totalTickets;
		ticket.IssueTime = clsDate::GetSystemDateTimeString();
		ticket.ExpectedServeTime = (GetWaitingClients() /*- 1*/) * _operationTime;

		_queue.push(ticket);
	}

	void PrintInfo()
	{

		string separatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t\t\tQueue Info\n";
		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t Prefix          = " << _prefix << '\n';
		cout << Spaces() << "\t Total Tickets   = " << _totalTickets << '\n';
		cout << Spaces() << "\t Served Clients  = " << _servedClients << '\n';
		cout << Spaces() << "\t Waiting Clients = " << GetWaitingClients() << '\n';
		cout << Spaces() << separatorLine << endl;

	}

	void PrintTicketsLineRTL() const
	{
		string rArrow = clsUtil::ColorText(" <-- ", clsUtil::enColor::BRIGHT_GREEN);

		if(_queue.IsEmpty()) cout << Spaces() << " Tickets: No Tickets... ";
		else cout << Spaces(30) << " Tickets: ";
		
		for (int i = 1; i <=_totalTickets; i++)
		{
			cout << _prefix << i << rArrow;
		}
		cout << endl;
	}

	void PrintTicketsLineLTR() const
	{
		string rArrow = clsUtil::ColorText(" --> ", clsUtil::enColor::BRIGHT_GREEN);

		if (_queue.IsEmpty()) cout << Spaces() << " Tickets: No Tickets... ";
		else cout << Spaces(30) << " Tickets: ";

		for (int i =_totalTickets; i >= 1; i--)
		{
			cout << _prefix << i << rArrow;
		}
		cout << endl;
	}

	void PrintTicket(const stTicket& ticket) const
	{
		string separatorLine = clsUtil::ColorText("_______________________________________\n", clsUtil::enColor::BRIGHT_MAGENTA);

		int waitingClients = (ticket.TicketNumber - _servedClients - 1);
		int expectedServeTime = waitingClients * GetWaitingClients();
		cout << Spaces(40) << separatorLine;
	
		cout << Spaces(40) << "\t\t" << _prefix << ticket.TicketNumber << '\n';
		cout << Spaces(40) << "\t" << ticket.IssueTime << '\n';
		cout << Spaces(40) << "\tWaiting Clients = " << waitingClients << '\n';
		cout << Spaces(40) << "\tServe Time In " << expectedServeTime << " Minutes.\n";

		cout << Spaces(40) << separatorLine;
		cout << endl;
	}

	void PrintAllTickets()
	{
		cout << endl;
		string Title = clsUtil::ColorText("\t\t     ---Tickets---\n",clsUtil::enColor::BRIGHT_GREEN);
		cout << Spaces(35) << Title;

		for (int i = 0; i < GetWaitingClients(); i++)
		{

			PrintTicket(_queue.GetItem(i));
		}

		/*clsMyQueue<stTicket> temp = _queue;

		while (!temp.IsEmpty())
		{
			PrintTicket(temp.front());
			if (temp.IsEmpty()) break;
			temp.pop();
		}*/

	}

	void ServeNextClient()
	{
		if (_queue.IsEmpty()) return;
		
		_queue.pop();
		++_servedClients;

	}

	string WhoIsNext() const
	{
		if (_queue.IsEmpty()) return "No Clients";

		return _prefix + to_string(_queue.front().TicketNumber);
	}

};

