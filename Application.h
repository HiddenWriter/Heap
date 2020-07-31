#pragma once

class Application {
public:
    Application();
    ~Application();

    int Run();

    int GetCommand();

	int GetHeapStat();

    int Add();

    int Delete();

    int Search();

    int Display();

	int Modify();

	int Clear();

	void GenerateHeap(int _status);
private:

	int heapStat;
    int command;
    HeapBase<ItemType>* ItemList;

};