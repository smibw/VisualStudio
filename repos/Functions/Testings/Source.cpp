#include 
#include  void hello()    
{
	std::cout << "Здравствуй, параллельный мир\n";
}
int main() 
{
	std::thread t(hello); 
	
		t.join();       
		
}