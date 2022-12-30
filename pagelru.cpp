#include<bits/stdc++.h>
using namespace std;
int check(int incomingPage, int queue[], int occupied)
{
   for (int i = 0; i < occupied; i++)
  {
   if (incomingPage == queue[i])
   return 1;
  }
 return 0;
}

void show(int queue[], int occupied)
{ 
   for (int i = 0; i < occupied; i++)
 {
  cout<<queue[i]<<"        ";
 }
}

int main()
{
  
  int n,frames;
  cout<<"Enter number of pages: ";
  cin>>n;
  cout<<"Enter number of frames: ";
  cin>>frames;
  int pages[n];
  cout<<"Enter pages values: ";
  for (int i = 0; i < n; i++)
 {
  cin>>pages[i];
 }
  int queue[n];
  int distance[n];
  int occupied = 0;
  int pagefault = 0;
  cout<<"Frame1   Frame2  Frame3  Frame4\n";
  for (int i = 0; i < n; i++)
 {
  if (check(pages[i], queue, occupied))
 {
  show(queue, occupied);
 }

  else if (occupied < frames)
 {
  queue[occupied] = pages[i];
  pagefault++;
  occupied++;
  show(queue,  occupied);
 }
 else
{
  int max = INT_MIN;
  int index;
  for (int j = 0; j < frames; j++)
 {
 distance[j] = 0;
 for (int k = i - 1; k >= 0; k--)
 {
  ++distance[j];
  if (queue[j] == pages[k])
  break;
 }
 if (distance[j] > max)
{
max = distance[j];
index = j;
}
}
  queue[index] = pages[i];
  show(queue,  occupied);
  pagefault++;
}
cout<<endl;
}
cout<<"Total number of Page Faults: "<< pagefault;
return 0;
}
