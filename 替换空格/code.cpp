class Solution {
public:
	void replaceSpace(char *str,int length) {
        /***********************************
        *解法一
        ***********************************/
        if(str == NULL || length <= 0)
            return;
        
        int space_count = 0;
        int len = 0;
        while(str[len] != '\0')
        {
            if(str[len] == ' ')
                space_count++;
            len++;
        }
        
        int new_len = len + space_count * 2;
        if(new_len > length)
            return;
        
        for(int i = len; i >= 0; i--)
        {
            if(str[i] == ' ')
            {
                str[new_len--] = '0';
                str[new_len--] = '2';
                str[new_len--] = '%';
            }
            else
            {
                str[new_len--] = str[i];
            }
        }
        
        /**************************************
        *解法二
        string newstr = "";
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == ' ')
                newstr += "%20";
            else
                newstr += str[i];
        }
        
        strcpy(str, newstr.c_str());
        ************************************/
	}
};
