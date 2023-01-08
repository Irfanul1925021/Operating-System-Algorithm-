#include <iostream>

using namespace std;

int main(){
     int
        t=0,
        i,
        j,
        numOfProcesses = 0,
        s=0,
        print=0,
        idle=0;
     float sum=0;

     cout << "Please enter the number of proces : ";
     cin >> numOfProcesses;

     int a[numOfProcesses][4];
     int b[numOfProcesses][5];

     cout<<"\n\nProcess\tArrival\tBurst\n-------\t-------\t-----\n";

     for(i = 0; i < numOfProcesses; i++){
          for(j = 0; j < 3; j++){
               cin >> a[i][j];
               }
          a[i][3] = a[i][2];
          }

     cout << "\n\nTime-Line is as follows (Verticle View)....\n\n";

     /**************************Processing Starts Here*************/
     for(i = 0, t = a[0][1]; i < numOfProcesses; i++){
          while(a[i][2] != 0){
               if(t >= a[i][1]){
                    if(print == 0)
                         printf("%5d-----------\n        |p-%-4d|\n", t, a[i][0]);
                    print = 1;
                    idle = 0;
                    a[i][2]--;
                    }
               else{
                    if(idle == 0){
                         printf("%5d-----------\n        |Idle  |\n", t);
                         idle = 1;
                         }
                    }
               t++;
               }
          print = 0;
          b[s][0] = a[i][0];
          b[s][1] = a[i][1];
          b[s][2] = t;
          b[s][3] = a[i][3];
          b[s][4] = ((t - a[i][1]) - a[i][3]);
          sum += b[s][4];
          s++;
          }

     printf("%5d-----------\n", t);
     /**************************Processing Ends Here*************/

     cout << endl << endl;
     cout << "Table of processes with completion record as they were completed\n\n";
     cout << "\n\nProcess\tArrival\tFinish\tTotal\tWait\n------------------------------------\n";

     for(i = 0; i < s; i++)
          cout << b[i][0] << "\t" << b[i][1] << "\t" << (b[i][2] - 1) << "\t" << b[i][3] << "\t" << b[i][4] << "\n";

     cout << "\n\nAvg. Wait time = " << (sum/numOfProcesses) << endl << endl;
     cout << "__________________________________________________________\nProgrammed by : Tanmay Chakrabarty, onlineclassnotes.com.\n\n";

     return 0;
     }
