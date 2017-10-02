<html>
<head>
	<style>
		#register_ln {
			font-size: 15px;
		}
	</style>
	<?php
		include("auth.php");
		session_start();

		if (isset($_GET["logout"]) && $_GET["logout"] == "true")
		{
			if (isset($_SESSION["loggued_on_user"]))
			{
				$user = $_SESSION["loggued_on_user"];
				create_raw_msg($user." has logged out");
				unset($_SESSION["loggued_on_user"]);
			}
			header('Location: index.php');
		}
	?>
	<title>Log in</title>
</head>
<body>
	<div align="center">
		<h1>Login</h1>
		<form action="login.php" method="POST">
			<table>
				<tr>
					<td align="center">Username</td>
					<td>
						<input type="text" name="login">
					</td>
					<td>
						<font color="red">
							<?php
								echo get_dex_str("login_field", $_SESSION);
								unset($_SESSION["login_field"]);
							?>
						</font>
					</td>
				</tr>
				<tr>
					<td align="center">Password</td>
					<td>
						<input type="password" name="passwd">
					</td>
					<td>
						<font color="red">
							<?php
								echo get_dex_str("passwd_field", $_SESSION);
								unset($_SESSION["passwd_field"]);
							?>
						</font>
					</td>					
				</tr>

				<tr>
					<td colspan="3" align="right">
						<a id="register_ln" href="create_html.php">Not registred?</a>
					</td>
				</tr>

				<tr>
					<td colspan="3" align="center">
						<input type="submit" name="submit" value="OK">
					</td>
				</tr>

			</table>
		</form>
	</div>
</body>
</html>