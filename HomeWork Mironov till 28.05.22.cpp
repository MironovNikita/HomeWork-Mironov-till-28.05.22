#include <iostream>
#include "String.cpp"
using namespace std;

//https://server.179.ru/tasks/cpp/total/161.html

int main()
{
    char* string1 = new char[] {"Hello! How are you?"};
    char* string2 = new char[] {" I\'ve not seen you for several years!"};
    String str(string1);
    String str2(string2);
    
    //1 Size of the string - str.size()
    cout << "The size of your 1st string is: " << str.size() << endl;
    cout << "The size of your 2nd string is: " << str2.size() << endl;
    cout << endl << "First original string: ";
    str.out();
    cout << "Second original string: ";
    str2.out();
    cout << endl;

    //2 Resize of the string - str.reSize()
    /*int n;
    cout << endl << "How many elements you want to create a new string from: ";
    cin >> n;
    if (str.size() >= n) str.reSize(n);
    else
    {
        char s;
        cout << "Input symbol you wish to add to your string: ";
        cin >> s;
        str.reSize(n, s);
    }
    str.out();*/

    //3 Clear the string - str.clear()
    /*str.clear();
    str.out();
    cout << endl << "The size of your string is: " << str.size();*/
    
    //4 The string is empty or not? - str.empty()
    /*str.clear(); //for empty check
    cout << "0 - your string is full, 1 - string is empty: " << str.empty();*/

    //5 Add the symbol to the end of the string - str.pus_back()
    /*char a;
    cout << "Input element you wish to add to your string: ";
    cin >> a;
    str.push_back(a);
    str.out();*/
    
    //6 Add to the end of the string several symbols, another string or part of the string - str.append()
    /*cout << "What do you wish to do with your string?" << endl;
    cout << "Input:"
        "\n - \"1\" if you want to add some similiar symbols;"
        "\n - \"2\" if you want to add some string;"
        "\n - \"3\" if you want to add several symbols of some string beginning from index." << endl;
    int q;
    cout << "Choose one of the variants (1-3): ";
    cin >> q;
    switch (q)
    {
        case 1:
            int n;
            char b;
            cout << "Input symbol you wish to add to the string: ";
            cin >> b;
            cout << "Input the amount of symbols: ";
            cin >> n;
            str.append(n, b);
            str.out();
            break;
        case 2:
            str.append(str2);
            str.out();
            break;
        case 3: 
            int index;
            int quant;
            cout << "Input index, which you want to copy the second string from (from 0 to " << str2.size() << "): ";
            cin >> index;
            cout << "Input quantity, how many elements you want to copy from the second string (max: " << str2.size() - index << "): ";
            cin >> quant;
            str.append(str2, index, quant);
            str.out();
            break;
    }*/
    
    //7 Erase symbols from the string from the symbol with some index to the end of the string - str.erase()
    /*cout << "What do you wish to do with your string?" << endl;
    cout << "Input:"
        "\n - \"1\" if you want to delete last elements from index;"
        "\n - \"2\" if you want to delete some elements." << endl;
    int q;
    int index;
    cout << "Choose one of the variants (1-2): ";
    cin >> q;
    switch (q)
    {
        case 1:
            cout << "Input index you want to delete your string from (from 0 to " << str.size() << "): ";
            cin >> index;
            str.erase(index);
            cout << endl << "Your new string:";
            str.out();
            break;
            
        case 2: 
            cout << "Input index you want to delete your string from (from 0 to " << str.size() << "): ";
            cin >> index;
            int quant;
            cout << "Input quantity of symbols you wish to delete: ";
            cin >> quant;
            str.erase(index, quant);
            str.out();
            break;
    }*/

    //8 Input to the middle of the string some symbols - str.insert()
    /*int index, index2, quant;
    char symbol;

    cout << "What do you wish to do with your string?" << endl;
    cout << "Input:"
        "\n - \"1\" if you want to input several similiar symbols;"
        "\n - \"2\" if you want to input another string from any symbol of the first string;"
        "\n - \"3\" if you want to input several symbols of another string;" << endl;
    int q;
    cout << "Choose one of the variants (1-3): ";
    cin >> q;
    switch (q)
    {
        case 1:
            cout << "Input index you want to input your symbol from (from 0 to " << str.size() << "): ";
            cin >> index;
            cout << "Input quantity of symbols you wish to add: ";
            cin >> quant;
            cout << "Input symbol you wish to add: ";
            cin >> symbol;

            str.insert(index, quant, symbol);
            str.out();
            break;
        case 2:
            cout << "Input index you want to input your string from (from 0 to " << str.size() << "): ";
            cin >> index;

            str.insert(str2, index);
            str.out();
            break;
        case 3:
            cout << "Input index you want to input your string from (from 0 to " << str.size() << "): ";
            cin >> index;
            cout << "Input index you want to copy another string from (from 0 to " << str2.size() << "): ";
            cin >> index2;
            cout << "Input how many elements you wish to copy from another string: ";
            cin >> quant;

            str.insert(str2, index, index2, quant);
            str.out();
            break;
    }*/
    
    //9 Returns the substring of the string from the symbol with some index and up to the end of the string - str.substr();
    /*String str3;
    int index, q;
    
    cout << "What do you wish to do with your string?" << endl;
    cout << "Input:"
        "\n - \"1\" if you want to get substring beginning from index and to the end;"
        "\n - \"2\" if you want to get substring beginning from index to some quantity." << endl;
    cin >> q;

    switch (q)
    {
    case 1:
        cout << "Input index you want to make new string (from 0 to " << str.size() << "): ";
        cin >> index;
        
        str3.substr(str, index);
        str3.out();
        break;
    case 2:
        int quant;
        cout << "Input index you want to make new string (from 0 to " << str.size() << "): ";
        cin >> index;
        cout << "Input quantity of symbols you wish to make new string: ";
        cin >> quant;

        str3.substr(str, index, quant);
        str3.out();
        break;
    }*/

    //10 Replaces a fragment of the string with several equal characters, another string, or a fragment of another string - str.replace()
    /*int q;
    cout << "What do you wish to do with your string?" << endl;
    cout << "Input:"
    "\n - \"1\" if you want to get string with some replaced symbols by entered symbol;"
    "\n - \"2\" if you want to get string with some replaced symbols by another string;"
    "\n - \"3\" if you want to get string with some replaced symbols by another string from some index and quantity of symbols." << endl;
    cin >> q;

    int index, quant1;

    switch (q)
    {
    case 1:
        int quant2;
        char s;
        cout << "Input index you wish to replace symbols (from 0 to " << str.size() << ") : ";
        cin >> index;
        cout << "Input quantity of symbols you wish to replace: ";
        cin >> quant1;
        cout << "Input symbol you wish to be placed: ";
        cin >> s;
        cout << "Input quantity of symbols you wish to be placed: ";
        cin >> quant2;

        str.replace(index, quant1, quant2, s);
        str.out();
        break;
    case 2:
        cout << "Input index you wish to replace symbols (from 0 to " << str.size() << ") : ";
        cin >> index;
        cout << "Input quantity of symbols you wish to replace: ";
        cin >> quant1;

        str.replace(index, quant1, str2);
        str.out();
    case 3:
        int index2, quant3;
        cout << "Input index you wish to replace symbols (from 0 to " << str.size() << ") : ";
        cin >> index;
        cout << "Input quantity of symbols you wish to replace: ";
        cin >> quant1;
        cout << "Input index you wish to replace symbols (from 0 to " << str2.size() << ") : ";
        cin >> index2;
        cout << "Input quantity of symbols you wish to take from the second string: ";
        cin >> quant3;

        str.replace(index, quant1, str2, index2, quant3);
        str.out();
    }*/
    
    /*11 Searches for the first occurrence of another string in this string. The index of the first character is returned,
    starting from which the adjustment is then equal to the original string - str.find() */
    /*char* string4 = new char[] {"you"};
    String str4(string4);
    
    int q;
    int index = 0;
    cout << "What do you wish to find?" << endl;
    cout << "Input:"
        "\n - \"1\" if you want to get index of the first similiar symbol;"
        "\n - \"2\" if you want to get index of the first several similiar symbols." << endl;
    cin >> q;

    switch (q)
    {
        case 1:
            cout << "Searching for: " << endl;
            str4.out();

            cout << "If you wish to search from some index, please input value (from 0 to " << str.size() << "): ";
            cin >> index;

            cout << "Result of searching is: " << str.find(str4, index);
        case 2:
            int quant;
            cout << "Searching for: " << endl;
            str4.out();

            cout << "Input index you want to search (from 0 to " << str.size() << "): ";
            cin >> index;
            cout << "Input quantity if symbols you wish to search: ";
            cin >> quant;

            cout << "Result of searching is: " << str.find(str4, index, quant);
    }*/
    
    //12 Searches for the last occurrence of a substring ("right" search) - str.rfind()
    /*char* string5 = new char[] {"are"};
    String str5(string5);
    int index, q;
    cout << "What do you wish to find?" << endl;
    cout << "Input:"
    "\n - \"1\" if you want to get index of the first similiar symbol;"
    "\n - \"2\" if you want to get index of the first several similiar symbols." << endl;
    cin >> q;
    switch (q)
    {
    case 1:
        cout << "Searching for: " << endl;
        str5.out();

        cout << "If you wish to search from some index, please input value (from 0 to " << str.size() << "): ";
        cin >> index;

        cout << "Result of searching is: " << str.rfind(str5, index) << endl;
        break;
    case 2:
        cout << "Searching for: " << endl;
        str5.out();

        cout << "If you wish to search from some index, please input value (from 0 to " << str.size() << "): ";
        cin >> index;

        int quant;
        cout << "How many symbols you wish to find: ";
        cin >> quant;

        cout << "Result of searching is: " << str.rfind(str5, index, quant) << endl;
        break;
    }*/

    //13 Searches in original string first occurrence of any of the characters of this string str - str.find_first_of()
    /*char* string6 = new char[] {"you?"};
    String str6(string6);
    int index;

    cout << "Searching for the index of the first symbol from string: ";
    str6.out();

    cout << "Please input index (from 0 to " << str.size() - 1 << "), if you wish to search from some index: ";
    cin >> index;

    cout << endl << "First index of the same symbol in the original and searching strings: " << str.find_first_of(str6, index);*/

    //14 Searches in original string last occurrence of any of the characters of this string str - str.find_last_of()
    /*char* string7 = new char[] {"Why?"};
    String str7(string7);
    int index;

    cout << "Searching for the index of the first symbol from string: ";
    str7.out();

    cout << "Please input index (from 0 to " << str.size() - 1 << "), if you wish to search from some index: ";
    cin >> index;

    cout << endl << "Last index of the same symbol in the original and searching strings: " << str.find_last_of(str7, index);*/

    //15 Searches in the original string for the first occurrence of another symbol than the symbols of another string - str.find_first_not_of()
    /*char* string8 = new char[] {"Hello! How is Tom?"};
    String str8(string8);
    int index;

    cout << "Searching for the index of the first mismatched symbol from string: ";
    str8.out();

    cout << "Please input index (from 0 to " << str.size() - 1 << "), if you wish to search from some index: ";
    cin >> index;

    cout << endl << "First index of different symbol in the original string from another: " << str.find_first_not_of(str8, index);*/

    //16 Searches in the original string for the last occurrence of another symbol than the symbols of another string - str.find_last_not_of()
    /*char* string9 = new char[] {"Are you thinking?"};
    String str9(string9);
    int index;
    
    cout << "Searching for the index of the first mismatched symbol from string: ";
    str9.out();

    cout << "Please input index (from 0 to " << str.size() - 1 << "), if you wish to search from some index: ";
    cin >> index;

    cout << endl << "Last index of different symbol in the original string from another: " << str.find_last_not_of(str9, index);*/

    //17 Returns a pointer to the memory area where the string characters are stored, returns a value of type char*
    cout << "Your first string is: " << str.c_str() << endl;
    cout << "Your second string is: " << str2.c_str() << endl;
    

}


    

    



