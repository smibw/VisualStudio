#include 
#include  void hello()    
{
	std::cout << "����������, ������������ ���\n";
}
int main() 
{
	std::thread t(hello); 
	
		t.join();       
		
}