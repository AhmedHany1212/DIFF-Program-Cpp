#include "DIFF_Prog.h"


//---------- compare two files line by line ------------------//
void compare_lines(file File_1,file File_2,int mode,int line_num,int pass_flag)
{
    for(int i = 0; i < File_1.Line.size(); i++)
    {
        // check if current character is a space
        if(File_1.Line[i] == ' ' && File_1.Line[i+1] != ' ')
        {
        // if it is a space, increment word count
        File_1.word_num++;
        }
    }
    for(int i = 0; i < File_2.Line.size(); i++)
    {
        // check if current character is a space
        if(File_2.Line[i] == ' ' && File_2.Line[i+1] != ' ')
        {
        // if it is a space, increment word count
        File_2.word_num++;
        }
    }
    // if numbers of lines are matched but numbers of words differ: program will print the line of both texts
    if(File_1.word_num!=File_2.word_num)
    {
        cout <<"line#"<<line_num << ":the strings are not equal " << endl ;
        cout << File_1.Line << endl;
        cout << File_2.Line << endl;
        pass_flag=0;
    }
    // if numbers of lines are matched and numbers of words are matched but word differ:
    // program will print the word of both texts.
    else
    {
        istringstream String_Stream_File1(File_1.Line);
        istringstream String_Stream_File2(File_2.Line);
        do {
            // Get the word from the istringstream
            String_Stream_File1 >> File_1.word;
            String_Stream_File2 >> File_2.word;
            //Ignore case mode: ignore capital and small letters differences
            if(mode==1)
            {
                transform(File_1.word.begin(), File_1.word.end(), File_1.word.begin(), ::tolower);
                transform(File_2.word.begin(), File_2.word.end(), File_2.word.begin(), ::tolower);
            }
            if ( File_1.word != File_2.word)
            {
                cout <<"line#"<<line_num << ":the strings are not equal " << endl ;
                cout << File_1.word << endl;
                cout << File_2.word << endl;
                pass_flag=0;
            }
            } while (String_Stream_File1);
    }


    // Not ignore spaces mode: not ignore numbers of spaces differences.
    if(mode==3)
    {
        for(int l=0;l<File_1.Line.size();l++) if(File_1.Line[l]==' ') File_1.num_spaces++;
        for(int m=0;m<File_2.Line.size();m++) if(File_2.Line[m]==' ') File_2.num_spaces++;
        if(File_1.num_spaces != File_2.num_spaces)
        {
            cout <<"line#"<<line_num << ":the strings are not equal " << endl ;
            cout << File_1.Line << endl;
            cout << File_2.Line << endl;
            pass_flag=0;

        }
    }


    File_1.word_num=0;
    File_2.word_num=0;

}
