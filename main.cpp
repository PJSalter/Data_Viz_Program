#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Step 1: Prompt the user for a title for data.
    string title;
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;
    cout << endl;

    // Step 2: Prompt the user for the headers of two columns of a table.
    string header1, header2;
    cout << "Enter the column 1 header:" << endl;
    getline(cin, header1);
    cout << "You entered: " << header1 << endl;
    cout << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, header2);
    cout << "You entered: " << header2 << endl;
    cout << endl;

    // Step 3: Prompt the user for data points.
    vector<string> data_strings;
    vector<int> data_integers;

    while (true)
    {
        cout << "Enter a data point (-1 to stop input):" << endl;
        string data_point;
        getline(cin, data_point);

        if (data_point == "-1")
            break;

        // Step 4: Perform error checking for the data point entries.
        size_t comma_pos = data_point.find(",");
        if (comma_pos == string::npos)
        {
            cout << "Error: No comma in string." << endl;
            cout << endl;
            continue;
        }

        if (data_point.find(",", comma_pos + 1) != string::npos)
        {
            cout << "Error: Too many commas in input." << endl;
            cout << endl;
            continue;
        }

        string data_string = data_point.substr(0, comma_pos);
        string data_integer_str = data_point.substr(comma_pos + 1);
        int data_integer;
        try
        {
            data_integer = stoi(data_integer_str);
        }
        catch (const exception &)
        {
            cout << "Error: Comma not followed by an integer." << endl;
            cout << endl;
            continue;
        }

        cout << "Data string: " << data_string << endl;
        cout << "Data integer: " << data_integer << endl;
        cout << endl;

        data_strings.push_back(data_string);
        data_integers.push_back(data_integer);
    }

    // Step 5: Output the information in a formatted table.
    cout << endl;
    cout << setw(33) << right << title << endl;
    cout << header1 << setw(22 - header1.length()) << " | " << setw(22) << right << header2 << endl;
    cout << "--------------------------------------------" << endl;
    for (size_t i = 0; i < data_strings.size(); ++i)
    {
        cout << setw(19) << left << data_strings[i] << " | " << setw(22) << right << data_integers[i] << endl;
    }
    cout << endl;

    // Step 6: Output the information as a formatted histogram.
    for (size_t i = 0; i < data_strings.size(); ++i)
    {
        cout << setw(20) << right << data_strings[i] << " ";
        for (int j = 0; j < data_integers[i]; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
