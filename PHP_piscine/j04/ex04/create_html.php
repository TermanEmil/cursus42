<?php
	include("auth.php");
	session_start();
?>

<html>
<head>
	<title>Register</title>
	<style>
		#warning {
			color: red;
		}

		td {
			text-align: center;
		}

		#already_reg {
			font-size: 13px;
			color: gray;
			text-align: right;
		}

	</style>
</head>
<body>
	<div align="center">
		<h1>Register</h1>
		<form action="create.php" method="POST">
			<table>
				<tr>
					<td align="center">Username</td>
					<td>
						<input type="text" name="login">
					</td>
				</tr>
				<tr>
					<td align="center">Password</td>
					<td>
						<input type="password" name="passwd">
					</td>			
				</tr>

				<tr>
					<td align="center">Repeat password</td>
					<td>
						<input type="password" name="repeat_passwd">
					</td>			
				</tr>

				<tr>
					<td align="center">
						<input type="submit" name="submit" value="OK">
					</td>

					<td>
						<a id="already_reg" href="index.php">Already registred</a>
					</td>
				</tr>

			</table>
		</form>
		<p id="warning">
			<?php
				echo get_dex_str("Warning", $_SESSION);
				unset($_SESSION["Warning"]);
			?>
		</p>
	</div>
</body>
</html>