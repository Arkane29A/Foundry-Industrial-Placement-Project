

#include "include/address_book.h"
#include "address_book_operators.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

void AddressBook::add(AddressBook::Entry person)
{

    //Try block to catch errors
    try
    {   //Takes input and adds it to the vector
        AddressContacts.push_back(person);
    }

    catch(Entry person)
    {
        //throws error if it arrives
        throw std::runtime_error("Incorrect data format.");
    }

}

void AddressBook::remove(AddressBook::Entry person)
{

    //try checks for errors
    try{
        //loops through all contacts to compare which one is the correct one
        for(int x = 0; x < AddressContacts.size(); x++)
        {
            if (person == AddressContacts[x]) //if found, removes the entry
            {
                AddressContacts.erase(AddressContacts.begin() + x);

            }
        }
    }
    catch(Entry person)
    {
        //Catches errors
        throw std::runtime_error("Incorrect data format");
    }

}

std::vector<AddressBook::Entry> AddressBook::sortedByFirstName()
{
        //Uses the sort function provided by C++ to organise alphabetically by first name
        std::sort(AddressContacts.begin(), AddressContacts.end(), [](const Entry &a, const Entry &b){
            return a.first_name < b.first_name;
        });

    return  AddressContacts;


}


std::vector<AddressBook::Entry> AddressBook::sortedByLastName()
{


    //Uses the sort function provided by C++ to organise alphabetically by last name

     std::sort(AddressContacts.begin(), AddressContacts.end(), [](const Entry &a, const Entry &b){
            return a.last_name < b.last_name;
        });

    return AddressContacts;

}

//Used as a helper function for the find function; Converts code into lowercase to allow for case-insensitive search
std::string toLowerCase(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

std::vector<AddressBook::Entry> AddressBook::find(const std::string& name)
{
    //output vector is created
    std::vector<Entry> output;

    //loops through all contacts
    for (const auto& entry : AddressContacts)
    {
        //finds if the first name or the last name is a substring
        if (toLowerCase(entry.first_name).find(toLowerCase(name)) != std::string::npos ||
            entry.last_name.find(name) != std::string::npos)
        {
            //adds to the vector
            output.push_back(entry);
        }
    }

    return output;
}