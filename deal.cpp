#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  string deal= "n";
  string ans;
  string name;
  string spaceholder;
  float box[26];
  int counter=0;
  int keep_box;
  int open_box[5];
  int cases_left = 26;
  float offer_amount;
  float potential_winning=0;
  float sum_offer=0;
  
  ifstream reader;
  reader.open("file.txt");
  
  for(int i=0;i<26;i++)
  {
    reader >> spaceholder >> box[i];
  }
  
  reader.close();
  
  cout << "Enter your name:" << endl;
  getline(cin,name);
  cout << name << ", welcome to Deal or No Deal!" << endl;
  
  cout << "Choose a box to keep  (Enter a number between 0 and 25)" << endl;
  cin >> keep_box;
  
  while (deal == "n")
  {
    counter++;
    for (int j=0;j<5;j++)
  {
    cout << "Choose a box to open  (Enter a number between 0 and 25)" << endl;
    cin >> open_box[j];
    cout << "It has " << fixed << showpoint << setprecision(2) << box[open_box[j]] << " inside" << endl;
    box[open_box[j]]=0;
  }
  
  cases_left -= 5;  
  
  for(int i=0;i<26;i++)
  {
   sum_offer += box[i];
  }
    
  offer_amount = 10000+(-2714.74 * cases_left)+(.040 * sum_offer);
    
  if (offer_amount > potential_winning)
  {
    potential_winning = offer_amount;
  }
  
    
  cout << "Banker offer: $" << offer_amount << endl;
  cout << "Remaining boxes" << endl;
 
    for(int i=0;i<26;i++)
  {
    if (box[i] == 0 || i == keep_box)
    {
      cout << "X  ";
    }
    else
    {
      cout << i << "  "; 
    }
  }
  
  
  cout << endl << "deal or no deal(d/n)" << endl;
  cin >> deal;
  }
  
  cout << "Let’s see how you did!" << endl;
  if (counter < 5)
  {
    cout << "Potential Winnings: $"<< box[keep_box] << endl;
    cout << "Winnings: $" << offer_amount << endl;
  }
  else
  {
    cout << "Potential Winnings: $" << potential_winning << endl;
    cout << "Winnings: $" <<  box[keep_box]  << endl;
  }
  
  
  cout << "Would you like to see amounts in remaining boxes?(yes/no)" << endl;
  cin >> ans;
  
  if (ans == "yes" || ans == "Yes")
  {
    cout << "Remaining boxes" << endl;
    for(int i=0;i<26;i++)
  {
   cout << "Box " << i << ": " << box[i] << endl; 
  }
  }
  
  return 0;
}