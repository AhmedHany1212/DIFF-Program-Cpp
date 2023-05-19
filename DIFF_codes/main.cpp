#include "DIFF_Prog.h"

int main()
{
	int mode;
	int pass_flag=1;

    string FileName1,FileName2;
	cout<<"enter first file name:"<<endl;
    cin>>FileName1;
	cout<<"enter second file name:"<<endl;
    cin>>FileName2;

    ifstream File1,File2;
	File1.open(FileName1);
	if (File1.fail())
    {
		cout << "File one doesn't exist \n" ;
		abort();
	}

	File2.open(FileName2);
	if (File2.fail())
    {
		cout << "File two doesn't exist \n" ;
		abort();
	}

	cout<<"enter mode number:"<<endl;
	cout<<"  0 for normal mode"<<endl;
	cout<<"  1 for Ignore case mode"<<endl;
	cout<<"  2 for Ignore blank lines mode"<<endl;
	cout<<"  3 for Not ignore spaces mode"<<endl;
	cout<<"  4 for Ignore lines mode"<<endl;
	cin >>mode;
	while(mode>4 || mode<0)
    {
	cout<<"wrong mode number"<<endl;
	cout<<"enter mode number again:"<<endl;
	cin >>mode;
    }


	file File_1,File_2;

	//Ignore lines mode: ignore number of lines differences when the words are identical
	if(mode==4)
	{
		while (File1 >> File_1.word ) // get a word from  file1
		{
			File2 >> File_2.word ; // get word from file 2
			// compare words
			if ( File_1.word != File_2.word)
			{
				cout <<"the strings are not equal " << endl ;
				cout << File_1.word << endl;
				cout << File_2.word << endl;
				pass_flag=0;
			}
		}
        File1.close();
        File2.close();
        // if there is no difference: program will show this in message and end program.
		if(pass_flag==1) cout <<"both texts are identical" << endl ;
		return 0;
	}

//---------- compare number of lines in both files ------------------//
	File_1.line_num = 0; File_2.line_num = 0;
	string file_line;

	while(!File1.eof())
	{
		getline(File1,file_line);
		if(mode==2) if(file_line.length() != 0)File_1.line_num++;
		if(mode!=2) File_1.line_num++;
	}
	File1.clear();   //  set new value for error control state  //
	File1.seekg(0,ios::beg);

	while(!File2.eof())
	{
		getline(File2,file_line);
		if(mode==2) if(file_line.length() != 0)File_2.line_num++;
		if(mode!=2) File_2.line_num++;
	}
	File2.clear();
	File2.seekg(0,ios::beg);

 	if(File_1.line_num != File_2.line_num)
	{
		cout << "Different number of lines in files!" << "\n";
		cout << "File1 has " << File_1.line_num << " lines and File2 has "
				     << File_2.line_num << " lines" << "\n";
		return 0;
	}
//---------- compare two files line by line ------------------//
	int line_num=0;
	File_1.word_num=0;
	File_2.word_num=0;

    while(getline(File1, File_1.Line))
    {
        getline(File2, File_2.Line);
        line_num++;
        File_1.num_spaces=0;
        File_2.num_spaces=0;
        //Ignore blank lines mode: ignore any blank lines differences.
        if(mode==2)
        {
            while(File_1.Line.length() == 0 && !File1.eof()) getline(File1, File_1.Line);
            while(File_2.Line.length() == 0 && !File2.eof()) getline(File2, File_2.Line);
        }
        compare_lines(File_1,File_2,mode,line_num,pass_flag);

    }
    // if there is no difference: program will show this in message and end program.
    if(pass_flag==1) cout <<"both texts are identical" << endl ;
    File1.close();
    File2.close();
	return 0;
}
