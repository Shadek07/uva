#include<iostream>

using namespace std;

int main()
{
	int arr[99][99];

	int mat,sumR  = 0,sumC = 0;

	int RowCheck = 1,ColCheck = 1;

	int SaveRowNum,SaveColNum;

	int RowFrequen = 0,ColFrequen = 0;

	

	cin >> mat;

	while(mat)
	{
		

		

		for(int i = 0;i<mat;i++)
		{
			for(int j = 0;j<mat;j++)
			{
				cin >> arr[i][j];
			}
		}


		for(int l = 0;l<mat;l++)  // find sum for each row
		{
			for(int m =0;m < mat;m++)
			{
				sumR += arr[l][m];
			}

			if((sumR%2) != 0)
			{

				RowCheck = 0;

				if(RowCheck == 0)
				{
					SaveRowNum = l;
				}

                RowFrequen++;// plus plus for odd summation in single row
			}

			sumR = 0;
		}
		
		
		for(int p = 0; p < mat;p++)   //find sum for each column
		{
			for(int q =0;q < mat;q++)
			{
				sumC += arr[q][p];
			}

			if((sumC%2) != 0)
			{

				ColCheck = 0;

				if(ColCheck == 0)
				{
					SaveColNum = p;
				}
				
				ColFrequen++;// plus plus for odd summation in single column
			}

			sumC = 0;
		}

		

		if(RowCheck==1 && ColCheck==1)
		{
			cout << "OK" << endl;
		}

         if(RowFrequen >= 2 || ColFrequen >= 2 )
		 {
			 cout << "Corrupt" << endl;
		 }

		 if(RowFrequen == 1 && ColFrequen == 1)
		 {
			 cout << "Change bit ";
			 cout << "(" << SaveRowNum + 1 << ","<< SaveColNum + 1 << ")";
			 
			 cout << "\n" ;
		 }
		 
		 RowCheck = 1,ColCheck = 1;
		 RowFrequen = 0,ColFrequen = 0;


		

		cin >> mat;
	}

	return 0;
}


