

#include "include/address_book.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

void AddressBook::add(AddressBook::Entry person)
{


    try
    {
        AddressContacts.push_back(person);
    }

    catch(Entry person)
    {

        throw std::runtime_error("Incorrect data format.");
    }

}

void AddressBook::remove(AddressBook::Entry person)
{


    try{
	for(int x = 0; x < AddressContacts.size(); x++)
    {
        if (person == AddressContacts[x])
        {
            AddressContacts.erase(AddressContacts.begin() + x);

        }
    }
    }
    catch(Entry person)
    {
        throw std::runtime_error("Incorrect data format");
    }

}

std::vector<AddressBook::Entry> AddressBook::sortedByFirstName()
{
    try {    std::sort(AddressContacts.begin(), AddressContacts.end(), [](const Entry &a, const Entry &b){
            return a.first_name < b.first_name;
        });}

    catch(std::vector<AddressBook::Entry> AddressBook)
    {
        throw std::runtime_error("Empty List or Incorrect data type!");
    }


}
}

std::vector<AddressBook::Entry> AddressBook::sortedByLastName()
{



    try {    std::sort(AddressContacts.begin(), AddressContacts.end(), [](const Entry &a, const Entry &b){
            return a.last_name < b.last_name;
        });}

    catch(std::vector<AddressBook::Entry> AddressBook)
    {
        throw std::runtime_error("Empty List or Incorrect data type!");
    }

}

std::vector<AddressBook::Entry> AddressBook::find(const std::string& name)
{
    //output vector is created
    std::vector<Entry> output;

    //try block
	try
    {
        
        for(int i = 0; i<AddressContacts.size(); i++) //Iterates through all current contacts
        {

            std::string CompareFirstName = AddressContacts[i].first_name; //retrives first name 
            std::string CompareSecondName = AddressContacts[i].last_name; //retrives last name


            if(name.find(CompareFirstName) != std::string::npos) //checks if it is a substring against first name
            {
                output.push_back(AddressContacts[i]); //adds to output vector
            }

            if(name.find(CompareSecondName) != std::string::npos)
            {
                output.push_back(AddressContacts[i]); //adds to output vector
            }

        }

        return output;

       
    }

    //catches any false data inputs
     catch(std::string& name)
        {
            throw std::runtime_error("Incorrect data format");
        }

    
    
}
