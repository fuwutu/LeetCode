class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> directories;
        string directory;
        size_t begin = 0;
        while (begin + 1 < path.size())
        {
            size_t end = path.find("/", begin + 1);
            if (end == string::npos)
            {
                end = path.size();
            }
            directory.assign(path, begin, end - begin);
            
            if (directory == "/..")
            {
                if (!directories.empty())
                {
                    directories.pop_back();
                }
            }
            else if (directory.compare("/") != 0 && directory.compare("/.") != 0)
            {
                directories.push_back(directory);
            }
            
            if (end == string::npos)
            {
                break;
            }
            begin = end;
        }
        
        string simplepath;
        for (string& directory : directories)
        {
            simplepath.append(directory);
        }
        if (simplepath.empty())
        {
            simplepath.append("/");
        }
        
        return simplepath;
    }
};
