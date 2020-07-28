#include "pch.h"
#include "Application.h"

Application::Application() {
	this->heapStat = -1;
    this->command = -1;
    return;
}

Application::~Application(){ return; }

int Application::Run() {
	bool isTerminated = false;

	switch (GetHeapStat())
	{
	case 1:
		GenerateHeap(1);
		break;
	case 2:
		GenerateHeap(2);
		break;
	case 0:
		return 1;
		exit(100);
		break;
	default:
		break;
	}

	while (!isTerminated) {
		switch (GetCommand()) {
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Search();
			break;
		case 4:
			Modify();
			break;
		case 5:
			Display();
			break;
		case 6:
			Clear();
			break;
		case 0:
			isTerminated = true;
			break;
		default:
			break;
		}

	}
	return 1;
}

int Application::GetHeapStat() {
	std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << "\t * 1. Create Max heap                              *\n";
	std::cout << "\t * 2. Create Min Heap                              *\n";
	std::cout << "\t * 0. Exit                                         *\n";
	std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << ":";
	std::cin >> this->heapStat;
	return this->heapStat;
}

int Application::GenerateHeap(int _status) {
	if (_status == 1) {
		this->ItemList = new HeapMax<ItemType>;
	}
	else if (_status == 2) {
		this->ItemList = new HeapMin<ItemType>;
	}
	return 1;
}

int Application::GetCommand() {
	
    std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << "\t * Simple Heap Programme.                          *\n";
    std::cout << "\t * 1 : Add data.                                   *\n";
    std::cout << "\t * 2 : Delete data.                                *\n";
    std::cout << "\t * 3 : Search data.                                *\n";
    std::cout << "\t * 4 : Modify Data.                                *\n";
	std::cout << "\t * 5 : Display all data.                           *\n";
	std::cout << "\t * 6 : Clear Tree.                                 *\n";
    std::cout << "\t * 0 : Exit.                                       *\n";
	std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << "\t: ";

    std::cin >> this->command;
    switch (this->command)
    {
    case 1:
        this->command = 1;
        break;
    case 2:
        this->command = 2;
        break;
    case 3:
        this->command = 3;
        break;
    case 4:
        this->command = 4;
        break;
	case 5:
		this->command = 5;
		break;
	case 6:
		this->command = 6;
		break;
	case 7:
		this->command = 7;
		break;
    case 0:
        this->command = 0;
        break;
    default:
        break;
    }
    return this->command;
}

int Application::Add() {
    
}

int Application::Delete() {
  
}

int Application::Search() {
   
}

int Application::Display() {
   
}

int Application::Modify() {
	
}

int Application::Clear() {
	
}