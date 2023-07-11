#include <iostream>
#include <Windows.h>
#include "Array.h"
#include "Vector.h"

using namespace std;

template <typename type>
type get_user_input()
{
    type   input;
    cin >> input;
    return input;
}

template <typename T>
class Special_Char_Array : public Array<T>
{
private:
    const string allowed_chars = "‘₴1234567890-=!\"No;%:?()_+/*\\,.";
    const int allowed_chars_size = allowed_chars.length();

    bool check_char(T elem) {
        for (int i = 0; i < allowed_chars_size; ++i)
        {
            if (elem == allowed_chars[i])
                return true;
        }
        return false;
    }

public:
    void display_allowe_chars()
    {
        cout << "Allowed list of characters: " << allowed_chars;
    }

    void add_char(T elem)
    {
        if (check_char(elem))
        {
            Array<T>::addElem(elem);
        }
        else
        {
            cout << "Invalid character: " << elem << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char user_input;
    Special_Char_Array<char> charArray;

    cout << "Enter characters from the allowed list\n";
    
    charArray.display_allowe_chars();
    cout << "\nEnter E for display array and exit\n";

    while (true)
    {
        cout << "Enter: ";
        user_input = get_user_input<char>();

        if (user_input == 'E' || user_input == 'e')
        {
            cout << charArray << endl;
            break;
        }
        else
        {
            charArray.add_char(user_input);
        }
    }

    return 0;
}