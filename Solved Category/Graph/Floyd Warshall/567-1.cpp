    #include <iostream>
    #include <algorithm>
    #include <iomanip>

    using namespace std;

    int main()
    {
        int Case = 0;
        while (true)
        {
            const int MAX = 20;
            const int INF = 999999999;
            int D[MAX][MAX] = { 0 };
           
            for (int i = 0; i < MAX; i++)
                for (int j = 0; j < MAX; j++)
                    if (i == j)
                        D[i][j] = 0;
                    else
                        D[i][j] = INF;

            for (int i = 0; i < MAX - 1; i++)
            {
                int Number = 0;
                if (!(cin >> Number))
                    return 0;
                for (int j = 0; j < Number; j++)
                {
                    int Country = 0;
                    cin >> Country;
                    D[i][Country - 1] = 1;
                    D[Country - 1][i] = 1;
                }
            }
           
            for (int k = 0; k < MAX; k++)
                for (int i = 0; i < MAX; i++)
                    for (int j = 0; j < MAX; j++)
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
           
            int Cases = 0;
            cin >> Cases;
            int From = 0;
            int To = 0;
           
            
                
            Case++;
            cout << "Test Set #" << Case << endl;
            for (int i = 0; i < Cases; i++)
            {
                cin >> From >> To;
                cout << setw(2) << From << " to " << setw(2) << To << ": ";
                cout << D[From - 1][To - 1] << endl;
            }
	    cout << endl;
        }
       
        return 0;
    }
