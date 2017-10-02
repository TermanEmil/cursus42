var $_COOCKIE= {};

function        onClickTodo(e)
{
    delete_cookie($(e.target).attr('name'));
    $(e.target).remove();
}

function        load()
{
    var cookies = getCookies();
    var total_str = getCookie('total_todo');
    var total_todo = parseInt((total_str == '') ? '0' : total_str);
    var count_cook = 0;
    
    if (isNaN(total_todo))
        total_todo = 0;
    for (var i = 0; i < cookies.length; i++)
    {
        if (cookies[i].includes('todo_val'))
        {
            cookies[i] = cookies[i].split('todo_val=');
            if (cookies[i][1] != undefined && cookies[i][1] != '')
            {
                if (count_cook >= total_todo)
                    break ;
                add_todo(cookies[i][1], count_cook);
                count_cook++;
                
            }
        }
    }

}

function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+ d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookies()
{
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    return (ca);
}

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    
    for(var i = 0; i <ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

var delete_cookie = function(name) {
    setCookie(name, '');
};

function        add_todo(str, index)
{
    var final_todo = index + 'todo_val';
    var div = document.createElement('div');
    var node = document.createTextNode(str);
    var attr = document.createAttribute('class');
    
    attr.value = 'todo_cell';
    div.setAttributeNode(attr);
    
    attr = document.createAttribute('name');
    attr.value = final_todo;
    div.setAttributeNode(attr);
    
    div.appendChild(node);
    
    var ft_list = document.getElementById('ft_list');

    ft_list.appendChild(div);

    $('.todo_cell').click(function (e)
    {
        if (confirm('Are you sure to delete the todo label?'))
        {
            delete_cookie($(e.target).attr('name'));
            $(e.target).remove();
        }
    });
    
    setCookie(final_todo, str, 1);
}

function        user_add_todo()
{
    var todo_val = prompt('Enter message');
    
    if (todo_val != null && todo_val != '')
    {
        var total_todo = parseInt(getCookie('total_todo'));
        
        add_todo(todo_val, total_todo);
        
        setCookie('total_todo', total_todo + 1);
    }
}