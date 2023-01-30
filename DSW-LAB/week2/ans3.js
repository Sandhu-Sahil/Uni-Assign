function translate(a)
{
    // Length of the string
    var len = a.length;
    var res="";

    for(let i=0; i<len ;i++)
    {
        if (a[i] == 'a' || a[i]== 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            res = res + a[i];
        }
        else if(a[i] == ' ')
        {
            res = res +a[i];
        }
        else
        {
            res =res+ a[i] + 'o' + a[i];
        }
    }
    return res;
}

var translation = translate("this is fun")
console.log(translation)