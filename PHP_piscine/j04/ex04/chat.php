<?php
	include("auth.php");
?>

<html>
<head>
	<style>
		.msg {
			background-color: #B0B0B0 ;
		}
	</style>
</head>
<body>
	<?php
		$chat = get_chat();
		if (count($chat) == 1)
			echo "Empty chat";
		else
			foreach ($chat as $msg)
			{
				echo $msg . '<br />';
			}
	?>
</body>
</html>