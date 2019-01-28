#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define INF 10001
#define min(a,b) ((a) < (b) ? (a) : (b))
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)

bool wayToSort(int i, int j) { return i > j; }

int n_planks, p_width;

set<int> p_lengths;

set<int>::iterator first;
set<int>::iterator last;
set<int>::iterator it;

int numbers_a [10001];
int numbers_b [10001];


int try_fit (int m, int n) {
	
	int n_rows = n / p_width;
	
	int complete_rows = 0;
	
	int planks_used = 0;
	
	first = p_lengths.begin();
	last = --p_lengths.end();
	
	while(first != last)
	{
		if ( (*last) == m )
		{
			planks_used++;
			complete_rows++;
			numbers_a [*last]--;
		}
		else if ( (*last) < m )
		{
			it = first;
			while (it != last)
			{
				if ( (*last) + (*it) == m )
				{	
					planks_used += 2;
					complete_rows++;
					numbers_a [*it]--;
					numbers_a [*last]--;
					if (numbers_a [*last] == 0) --last;
					if (numbers_a [*it] == 0) break;
					++it;
				}
				else if ( (*last) + (*it) < m )
				{
					first = ++it;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	/*for (int i = 0; (complete_rows < n_rows) && (i < n_planks); i++)
	{
		if	(p_lengths[i] == m)
		{
			planks_used++;
			complete_rows++;
			
		}
		// Skip used plank and plank longer than the floor
		else if (p_lengths[i] < m)
		{	
			for (int j = end; j > i; j--)
			{
				if (p_lengths[i] + p_lengths[j] == m )
				{	
					planks_used += 2;
					complete_rows++;
					end = j-1;
					break;	
				}
				else if (p_lengths[i] + p_lengths[j] < m )
				{
					end = j-1;
				}
			}
		}
	}*/
	
	// check if solution was found
	return (complete_rows == n_rows)? planks_used : INF;
} 


int main () {
	
	int m, n; // m and n: Dimensions ballrooom
	
	int solution, value, input;
	
	while (sc2(m, n) && (m || n) )
	{
		memset(numbers_a, 0, sizeof(numbers_a));
		memset(numbers_b, 0, sizeof(numbers_b));
		
		sc2(p_width, n_planks);

		for (int i = 0 ; i < n_planks; i++)
		{
			sc1(input);
			p_lengths.insert (input);
			numbers_a[input]++;
			numbers_b[input]++;
		}
		
		solution = INF;
/*		if ((n*100) % p_width == 0)
		{
			solution = try_fit ( m, n*100 );
		}
		if ((m*100) % p_width == 0)  
		{
			value = try_fit ( n, m*100 );
		 	solution = min (value , solution);
		}
		if (solution < INF)
			printf("%d\n", solution);
		else
			puts("impossivel");
	*/}
	
	return 0;
}