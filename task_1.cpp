#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ifstream fin("program.cpp");

    if(!fin)
    {
        cout<<"Cannot open file";
        return 0;
    }

    string line;
    int lineNo=0;

    string variables[100];
    int varCount=0;

    char operators[100];
    int opCount=0;

    int libCount=0;


    while(getline(fin,line))
    {
        lineNo++;


        // Library detection
        if(line.find("#include") == 0)
        {
            int l=line.find('<');
            int r=line.find('>');

            if(l!=-1 && r!=-1)
            {
                libCount++;
                cout<<"Library-"<<libCount<<": "
                    <<line.substr(l+1,r-l-1)<<endl;
            }
        }


        // Comment detection
        int c=line.find("//");

        if(c!=-1)
        {
            cout<<"Comment in line - "<<lineNo<<endl;
        }


        // Missing semicolon
        string temp=line;

        while(temp.length()>0 &&
             (temp[temp.length()-1]==' ' || temp[temp.length()-1]=='\t'))
        {
            temp.pop_back();
        }


        if(temp.length()>0 &&
           temp[0]!='#' &&
           temp[temp.length()-1]!=';' &&
           temp[temp.length()-1]!='{' &&
           temp[temp.length()-1]!='}')
        {
            cout<<"';' missing in line - "<<lineNo<<endl;
        }


        // Missing parenthesis
        int open=0, close=0;

        for(int i=0;i<line.length();i++)
        {
            if(line[i]=='(')
                open++;

            if(line[i]==')')
                close++;
        }

        if(open!=close)
        {
            cout<<"missing parenthesis."<<endl;
        }


        // Integer detection
        for(int i=0;i<line.length();i++)
        {
            if(isdigit(line[i]))
            {
                string num="";

                while(i<line.length() && isdigit(line[i]))
                {
                    num += line[i];
                    i++;
                }

                cout<<"'"<<num<<"' is an integer"<<endl;
            }
        }



        // Invalid variable like 1f
        for(int i=0;i<line.length()-1;i++)
        {
            if(isdigit(line[i]) && isalpha(line[i+1]))
            {
                string invalid="";

                while(i<line.length() &&
                     (isalnum(line[i])))
                {
                    invalid+=line[i];
                    i++;
                }

                cout<<"Invalid variable - "<<invalid<<endl;
            }
        }



        // Invalid expression
        if(line.find("@")!=-1)
        {
            cout<<"Invalid expression in line - "
                <<lineNo<<endl;
        }

        if(line.find("-;")!=-1)
        {
            cout<<"Invalid expression in line - "
                <<lineNo<<endl;
        }



        // Variable detection
        for(int i=0;i<line.length();i++)
        {
            if(isalpha(line[i]) || line[i]=='_')
            {
                string word="";

                while(i<line.length() &&
                     (isalnum(line[i]) || line[i]=='_'))
                {
                    word+=line[i];
                    i++;
                }


                if(word!="include" &&
                   word!="int" &&
                   word!="string" &&
                   word!="using" &&
                   word!="namespace" &&
                   word!="return")
                {
                    bool exists=false;

                    for(int j=0;j<varCount;j++)
                    {
                        if(variables[j]==word)
                            exists=true;
                    }

                    if(!exists)
                    {
                        variables[varCount]=word;
                        varCount++;
                    }
                }
            }
        }



        // Operator detection
        for(int i=0;i<line.length();i++)
        {
            if(line[i]=='+' || line[i]=='-' || line[i]=='*')
            {
                bool exists=false;

                for(int j=0;j<opCount;j++)
                {
                    if(operators[j]==line[i])
                        exists=true;
                }

                if(!exists)
                {
                    operators[opCount]=line[i];
                    opCount++;
                }
            }
        }

    }


cout<<"   ----    "<<endl;
    // Print variables
    for(int i=0;i<varCount;i++)
    {
        cout<<"Variable-"<<i+1<<": "
            <<variables[i]<<endl;
    }

    cout<<"Total number of the variables: "
        <<varCount<<endl;



    // Print operators
    for(int i=0;i<opCount;i++)
    {
        cout<<"Operator-"<<i+1<<": "
            <<operators[i]<<endl;
    }

    cout<<"Total number of the operators: "
        <<opCount<<endl;


    fin.close();

    return 0;
}
