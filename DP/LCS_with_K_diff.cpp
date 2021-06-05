#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'substringDiff' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. STRING s1
 *  3. STRING s2
 */

int substringDiff(int k, string string1, string string2)
{
    int length = string1.size();
    int diff_array[length][length];

    int j, i;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
            diff_array[i][j] = (string1[i] != string2[j]);
    }
    int front_pointer, back_ptr1, back_ptr2, front_sum1, front_sum2, curr_max = -1;
    int back_sum1, back_sum2;
    for (i = 0; i < length; i++)
    {
        front_sum1 = front_sum2 = back_sum1 = back_sum2 = 0;
        back_ptr1 = back_ptr2 = -1;
        for (front_pointer = 0; front_pointer + i < length; front_pointer++)
        {
            front_sum1 += diff_array[front_pointer][i + front_pointer];
            front_sum2 += diff_array[i + front_pointer][front_pointer];
            while (front_sum1 - back_sum1 > k)
            {
                back_ptr1++;
                back_sum1 += diff_array[back_ptr1][i + back_ptr1];
            }
            while (front_sum2 - back_sum2 > k)
            {
                back_ptr2++;
                back_sum2 += diff_array[i + back_ptr2][back_ptr2];
            }

            if (front_pointer - back_ptr1 > curr_max)
                curr_max = front_pointer - back_ptr1;
            if (front_pointer - back_ptr2 > curr_max)
                curr_max = front_pointer - back_ptr2;
        }
    }

    return curr_max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int k = stoi(first_multiple_input[0]);

        string s1 = first_multiple_input[1];

        string s2 = first_multiple_input[2];

        int result = substringDiff(k, s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
