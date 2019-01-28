#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void swapOperations (string& expression, char op, int start, int end)
{
    char aux = op;
    for (int i = start; i <= end; i++)
    {
        expression[i-1] = expression[i];    
    }
    expression[end] = aux;

}

string removeParentheses(const string& expression)
{
    stringstream ss;
    
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] != '(' && expression[i] != ')')
            ss << expression[i];
    }
    return ss.str();
}


void findOperations (string& expression, int start, int end)
{
    int countParenteses = 0;
    while(end > start)
    {
        for (int k = 0; k < 3; k++)
        {
            for (int i = end; i >= start; i--)
            {
                if (   k == 2 && expression[i] == '^' && countParenteses == 0
                || k == 1 && (expression[i] == '*' || expression[i] == '/') && countParenteses == 0
                || k == 0 && (expression[i] == '+' || expression[i] == '-') && countParenteses == 0)
                {
                    char op = expression[i];
                    findOperations (expression, start, i - 1);  
                    findOperations (expression, i + 1, end);
                    return swapOperations (expression, op, i + 1, end);
                
                }
                else if (expression[i] == ')' )
                    countParenteses++;
                else if (expression[i] == '(' )
                    countParenteses--;
            }   
        }
        start++;
        end--;
    }
    return;
}

    
int main()
{
    int N;
    cin >> N;
    
    string expressions[N];
    char aux;
    
    for (int i = 0; i < N; i++)
    {
        cin >> expressions[i] ;
        findOperations (expressions[i], 0, expressions[i].length() - 1);
        cout << removeParentheses (expressions[i]) << endl;
    }
    return 0;
}
