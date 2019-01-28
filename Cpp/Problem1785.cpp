#include <iostream>

using namespace std;

int get_highest(int v1, int v2, int v3, int v4)
{
	int v[] = {v1, v2, v3, v4};
	int aux;
	// v1 com v2
	if (v[0] < v[1])
	{
		aux  = v[0];
		v[0] = v[1];
		v[1] = aux;
	}
	if (v[2] < v[3])
	{
		aux  = v[2];
		v[2] = v[3];
		v[3] = aux;
	}
	if (v[0] < v[2])
	{
		aux  = v[0];
		v[0] = v[2];
		v[2] = aux;
	}
	if (v[1] < v[2])
	{
		aux  = v[1];
		v[1] = v[2];
		v[2] = aux;
	}
	if (v[2] < v[3])
	{
		aux  = v[2];
		v[2] = v[3];
		v[3] = aux;
	}
	if (v[1] < v[2])
	{
		aux  = v[1];
		v[1] = v[2];
		v[2] = aux;
	}
	
	return v[0]*1000 + v[1]*100 + v[2]*10 + v[3];

}

int get_lowest (int val_input) // maior
{
	int v1 =  val_input / 1000;
	int v2 = (val_input % 1000) / 100;
	int v3 = (val_input % 100 ) /  10;
	int v4 = (val_input % 10);
	
	return v4*1000 + v3*100 + v2*10 + v1;
}

int main()
{
	
	int test_cases = 0;
	int val_input;
	int v1,v2,v3,v4;
	
	cin >> test_cases;
	
	for (int i=0; i < test_cases; i++)
	{
		cin >> val_input;

		v1 =  val_input / 1000;
		v2 = (val_input % 1000) / 100;
		v3 = (val_input % 100 ) /  10;
		v4 = (val_input % 10);
		
		if (v1==v2 && v2==v3 && v3==v4)
		{
			cout << "Caso #" << (i+1) << ": -1" << endl;
		}
		else
		{
			int kap = val_input;
			int cont = 0;
			int hi, lo;
			while (kap != 6174)
			{
				hi = get_highest (v1,v2,v3,v4);
				lo = get_lowest (hi);
				kap = hi-lo;
				cont++;
				//cout << hi << "  " <<lo<<endl;
				v1 =  kap / 1000;
				v2 = (kap % 1000) / 100;
				v3 = (kap % 100 ) /  10;
				v4 = (kap % 10);
				
			}
			
			cout << "Caso #" << (i+1) << ": " << cont << endl;
		}
	}
	
	return 0;
}