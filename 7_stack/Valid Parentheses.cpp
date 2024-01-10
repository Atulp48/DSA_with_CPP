bool isValidParenthesis(string expression)
{

    stack<char> str;
    for (int x = 0; x < expression.length(); x++)
    {
        char flag = expression[x];
        if (flag == '[' || flag == '(' || flag == '{')
        {
            str.push(flag);
        }
        else
        {
            if (!str.empty())
            {
                char flag1 = str.top();
                if ((flag == ']' && flag1 == '[') || (flag == ')' && flag1 == '(') ||
                    (flag == '}' && flag1 == '{'))
                {
                    str.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (str.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}