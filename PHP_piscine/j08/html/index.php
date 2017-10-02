<!DOCTYPE html>
<html>
<head>
    <title>Log in</title>
</head>
    <div align="center">
        <h1>Space battlefield</h1>
        <h2>Log in</h2>
        
        <form method="post" action="/php/login.php">
            <table>
                
                <tr>
                    <td>Username: </td>
                    <td><input type="text" name="login"/></td>
                </tr>
                
                <tr>
                    <td>Password: </td>
                    <td><input type="password" name="passwd"/></td>
                </tr>
        
                <tr>
                    <td colspan="2" align="right">
                        <a style="font-size: 10px" href="">Already registred?</a>
                    </td>
                </tr>
        
                <tr>
                    <td  colspan="2" align="center">
                        <input type="submit" name="submit_login" value="LogIn"/>
                    </td>
                </tr>
                
            </table>
        </form>
        
    </div>
</html>