using namespace std;
#include <cmath>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<map>
void saveToFile(const string& filename, const vector<string>& data)
{
    ofstream out (filename);
    if (!out.is_open())
    {
        cout<<"cant open"<<endl;
    }
    for (int i=0;i<3;++i)
    {
        out<<data[i]<< " ";
    }
    out.close();
}
void loadFromFile(const string& filename, vector<string>& outData)
{
    ifstream in (filename);
    string str;
    if(in.is_open())
    {
        while(getline(in, str))
        {
          cout<<str<<endl;
        }
    }
    else
    {
        cout<<"file cant open"<<endl;
    }
}
struct Book
{
 string Author;
 string Title;
 int Year;
};
void saveToFileB(const string& filename1, const struct Book& data)
{

    ofstream out (filename1);
    if (!out.is_open())
    {
        cout<<"cant open"<<endl;
    }
    for (int i=0;i<1;++i)
    {
        out<<data.Author<<" "<<data.Title<<" "<<data.Year<<endl;;
    }
    out.close();

}
void loadFromFileB(const string& filename1, vector<string>& outData)
{
    ifstream in (filename1);
    string str;
    if(in.is_open())
    {
        while(getline(in, str))
        {
          outData.push_back(str);
        }
    }
    else
    {
        cout<<"file cant open"<<endl;
    }
    for (int i=0; i < outData.size(); ++i)
    {
        cout << outData[i];
    }
    in.close();
}
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<string, Score> RecordBook;
};

// â êà÷åñòâå êëþ÷à - íàçâàíèå ãðóïïû
// â êà÷åñòâå çíà÷åíèÿ - ñïèñîê ñòóäåíòîâ
using Groups = std::map<std::string, std::vector<Student>>;
void saveToFileGroups(const string& filename, const Groups& groups)
{
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "can't open file" << endl;
    }
    for (auto& elem : groups.at("IU8-14")) {
        out << elem.Name << ' ' << elem.Year << ' ' << elem.RecordBook.at("Math") << std::endl;
    }
    out.close();
}

void loadFromFileGroups(const std::string& filename, Groups& outGroups) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "can't open file" << endl;
        return;
    }
    string str;
    vector <Student> s1;
    while (getline(in, str)) {
        Student student;
        istringstream iss(str);
        string name;
        iss >> name;
        student.Name = name;
        int year;
        iss >> year;
        student.Year = year;
        int score;
        iss >> score;
        student.RecordBook["Math"] = static_cast<Score>(score);
        s1.push_back(student);
    }
    outGroups["IU8-14"] = s1;
}

int main() {
    vector<string>m1={"i","am","eating"};
    vector<string>k2;
    string filename ="fail1.txt";
    string filename1 ="fail2.txt";
    saveToFile(filename,m1);
    loadFromFile(filename,m1);
    Book k1= {"Jane Austin","Pride and Prejudice",1813};
    saveToFileB(filename1,k1);
    loadFromFileB(filename1,k2);




    Groups g1;
    vector <Student> s3;
    Student s1;
    s1.Name = "anastasia";
    s1.Year = 18;
    s1.RecordBook["Math"] = Excellent;
    Student s2;
    s2.Name = "Misha";
    s2.Year = 17;
    s2.RecordBook["Math"] = Satisfactorily;
    s3.push_back(s1);
    s3.push_back(s2);
    g1["IU8-14"] = s3;
    saveToFileGroups(filename, g1);
    Groups g2;
    loadFromFileGroups(filename, g2);
    return 0;
}
