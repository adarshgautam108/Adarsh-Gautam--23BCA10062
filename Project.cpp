#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class SpamFilter {
private:
    vector<string> spamKeywords;

public:
   
    SpamFilter() {
        spamKeywords = {
            "free", "win", "winner", "click here", "buy now", "urgent", "limited time", "lottery", "money", "offer"
        };
    }

    
    bool isSpam(const string& email) {
        
        string lowerEmail = email;
        transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);
        
        
        for (const auto& keyword : spamKeywords) {
            if (lowerEmail.find(keyword) != string::npos) {
                return true;
            }
        }
        return false;
    }


    void displayKeywords() {
        cout << "Spam Keywords:" << endl;
        for (const auto& keyword : spamKeywords) {
            cout << "- " << keyword << endl;
        }
    }
};

int main() {
    SpamFilter spamFilter;
    string email;

    cout << "Email Spam Filter\n";
    spamFilter.displayKeywords();

    while (true) {
        cout << "\nEnter an email (or type 'exit' to quit): ";
        getline(cin, email);
        if (email == "exit") break;

        if (spamFilter.isSpam(email)) {
            cout << "The email is classified as: SPAM" << endl;
        } else {
            cout << "The email is classified as: NOT SPAM" << endl;
        }
    }

    return 0;
}