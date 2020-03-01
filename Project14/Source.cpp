#include<iostream>
#include<string>
using namespace std;
class PC 
{
	Box* box;
	Processor* processor;
	MainBoard* mainBoard;
	Hdd* hdd;
	Memory* memory;
public:
	PC() {
		box = NULL;
		processor = NULL;
		mainBoard = NULL;
		hdd = NULL;
		memory = NULL;
	}
	virtual ~PC() {
		if (box)
			delete box;
		if (processor)
			delete processor;
		if (mainBoard)
			delete mainBoard;
		if (hdd)
			delete hdd;
		if (memory)
			delete memory;
	}
	Box* GetBox() {
		return box;
	}
	void SetBox(Box* pBox) {
		box = pBox;
	}
	Processor* GetProcessor() {
		return processor;
	}
	void SetProcessor(Processor* pProcessor) {
		processor = pProcessor;
	}
	MainBoard* GetMainBoard() {
		return mainBoard;
	}
	void SetMainBoard(MainBoard* pMainBoard) {
		mainBoard = pMainBoard;
	}
	Hdd* GetHdd() {
		return hdd;
	}
	void SetHdd(Hdd* pHdd) {
		hdd = pHdd;
	}
	Memory* GetMemory() {
		return memory;
	}
	void SetMemory(Memory* pMemory) {
		memory = pMemory;
	}
};

class IPCFactory {
public:
	virtual Box* CreateBox() = 0;
	virtual Processor* CreateProcessor() = 0;
	virtual MainBoard* CreateMainBoard() = 0;
	virtual Hdd* CreateHdd() = 0;
	virtual Memory* CreateMemory() = 0;
};

class HomePcFactory : public IPCFactory {
public:
	Box* CreateBox()
	{
		return new SilverBox();
	}
	Processor* CreateProcessor()
	{
		return new IntelProcessor();
	}
	MainBoard* CreateMainBoard()
	{
		return new MSIMainBord();
	}
	Hdd* CreateHdd()
	{
		return new SamsungHDD();
	}
	Memory* CreateMemory()
	{
		return new Ddr2Memory();
	}
};

class OfficePcFactory : public IPCFactory {
public:
	Box* CreateBox()
	{
		return new BlackBox();
	}
	Processor* CreateProcessor()
	{
		return new AmdProcessor();
	}
	MainBoard* CreateMainBoard()
	{
		return new AsusMainBord();
	}
	Hdd* CreateHdd()
	{
		return new LGHDD();
	}
	Memory* CreateMemory()
	{
		return new DdrMemory();
	}
};

class PcConfigurator
{
	IPCFactory* pcFactory;
public:
	PcConfigurator() {
		pcFactory = NULL;
	}
	virtual ~PcConfigurator() {
		if (pcFactory)
			delete pcFactory;
	}
	IPCFactory* GetPCFactory() {
		return pcFactory;
	}
	void SetPCFactory(IPCFactory* pcCurrentFactory) {
		pcFactory = pcCurrentFactory;
	}
	void Configure(PC* pc)
	{
		pc->SetBox(pcFactory->CreateBox());
		pc->SetMainBoard(pcFactory->CreateMainBoard());
		pc->SetHdd(pcFactory->CreateHdd());
		pc->SetMemory(pcFactory->CreateMemory());
		pc->SetProcessor(pcFactory->CreateProcessor());
	}
};



int main()
{

}