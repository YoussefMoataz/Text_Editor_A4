fstream read((fileName + ".txt").c_str(), ios::in);

    string word;
    int counter = 0;

    while(read >> word)
    {
        if(!iswspace(word))
            counter++;
    }

    cout << "the file has " << counter << " words" << endl;