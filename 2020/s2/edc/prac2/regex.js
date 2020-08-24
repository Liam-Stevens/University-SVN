function checkMatch(str)
{
    //Cannot match nothing
    if (str == null)
    {
        return false
    }

    //Matches a+
    if (str[0] === 'a')
    {
        return matchFirst(str)
    }

    //Matches bb*a
    if (str[0] === 'b')
    {
        return matchSecond(str)
    }

    return false
}

//Matches a+
function matchFirst(str)
{
    //One or more 'a' characters
    var i
    for (i = 0; i < str.length; i++)
    {
        if (str[i] !== 'a')
        {
            return false
        }
    }
    return true
}

//Matches bb*a
function matchSecond(str)
{
    //One or more 'b' characters
    var i
    for (i = 0; i < str.length-1; i++)
    {
        if (str[i] !== 'b')
        {
            return false
        }
    }

    //Ending in 'a'
    if (str[str.length-1] === 'a')
    {
        return true
    }
    else
    {
        return false
    }
}
