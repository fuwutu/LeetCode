class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ips;
        string ip1, ip2, ip3, ip4;
        int total_len = s.length();
        for (int len1 = 1; len1 <= min(3, total_len - 3); ++len1)
        {
            ip1 = s.substr(0, len1);
            int num1 = atoi(ip1.c_str());
            if ((len1 > 1 && s[0] == '0') || num1 > 255)
            {
                break;
            }
            for (int len2 = 1; len2 <= min(3, total_len - len1 - 2); ++len2)
            {
                ip2 = s.substr(len1, len2);
                int num2 = atoi(ip2.c_str());
                if ((len2 > 1 && s[len1] == '0') || num2 > 255)
                {
                    break;
                }
                for (int len3 = 1; len3 <= min(3, total_len - len1 - len2 -1); ++len3)
                {
                    
                    ip3 = s.substr(len1 + len2, len3);
                    int num3 = atoi(ip3.c_str());
                    if ((len3 > 1 && s[len1 + len2] == '0') || num3 > 255)
                    {
                        break;
                    }
                    int len4 = total_len - len1 - len2 - len3;
                    if (len4 <= 3)
                    {
                        ip4 = s.substr(len1 + len2 + len3, len4);
                        int num4 = atoi(ip4.c_str());
                        if (!(len4 > 1 && s[len1 + len2 + len3] == '0') && num4 <= 255)
                        {
                            ips.push_back(ip1 + "." + ip2 + "." + ip3 + "." + ip4);
                        }
                    }
                }
            }
        }
        return ips;
    }
};
