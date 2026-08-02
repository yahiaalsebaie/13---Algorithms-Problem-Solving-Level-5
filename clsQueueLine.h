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
	std::string _prefix = "";
	int _operationTime = 0;
	clsMyQueue<int> _queue;
	int _servedClients = 0;
	int _totalTickets = 0;


private:
	int GetWaitingClients() const
	{
		return _totalTickets - _servedClients;
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
	clsQueueLine(const std::string& prefix, const int& OperationTime) : _prefix(prefix), _operationTime(OperationTime) {}

	
	void IssueTicket()
	{
		++_totalTickets;
		_queue.push(_totalTickets);

	}

	void PrintInfo()
	{

		string separatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t\t\tQueue Info\n";
		cout << Spaces() << separatorLine;
		cout << Spaces() << "\t Prefix          = " << _prefix << "\n";
		cout << Spaces() << "\t Total Tickets   = " << _totalTickets << "\n";
		cout << Spaces() << "\t Served Clients  = " << _servedClients << "\n";
		cout << Spaces() << "\t Waiting Clients = " << GetWaitingClients() << "\n";
		cout << Spaces() << separatorLine << endl;

	}

	void PrintTicketsLineRTL() const
	{
		string rArrow = clsUtil::ColorText(" <-- ", clsUtil::enColor::BRIGHT_GREEN);

		cout << Spaces(30) << " Tickets: ";
		for (int i = 1; i <= _totalTickets; i++)
		{
			cout << _prefix << i << rArrow;
		}
		cout << endl;
	}

	void PrintTicketsLineLTR() const
	{
		string rArrow = clsUtil::ColorText(" --> ", clsUtil::enColor::BRIGHT_GREEN);

		cout << Spaces(30) << " Tickets: ";
		for (int i = _totalTickets; i >= 1; i--)
		{
			cout << _prefix << i << rArrow;
		}
		cout << endl;
	}

	void PrintTicket(int ticketNumber) const
	{
		string separatorLine = clsUtil::ColorText("_______________________________________\n", clsUtil::enColor::BRIGHT_MAGENTA);

		cout << Spaces(40) << separatorLine;
		cout << Spaces(40) << "\t\t  " << _prefix << ticketNumber << "\n";
		cout << Spaces(40) << "\t " << clsDate::GetSystemDateTimeString() << endl;
		cout << Spaces(40) << "\t Waiting Clients = " << (--ticketNumber) << "\n";
		cout << Spaces(40) << "\t Serve Time In " << (_operationTime * (ticketNumber)) << " Minutes.\n";
		cout << Spaces(40) << separatorLine;
		cout << endl;
	}

	void PrintAllTickets()
	{
		cout << endl; 
		string Title = clsUtil::ColorText("\t\t     ---Tickets---\n",clsUtil::enColor::BRIGHT_GREEN);

		cout << Spaces(35) << Title;
		for (int ticketNumber = 1; ticketNumber <= GetWaitingClients(); ++ticketNumber)
		{
			PrintTicket(ticketNumber);
		}

	}

	void ServeNextClient()
	{
		if (_queue.IsEmpty()) return;
		
		_queue.pop();
		++_servedClients;

	}



};

