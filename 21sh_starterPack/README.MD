* ft_errors.h
	In caz ca vrem sa printam o eroare de gen:
		"21sh: a error has occured"
		trebuie intai te initializat ft_errors cu numele proiectului
			trebuie in main de apelat `void		ft_err_init_proj_name(PRJ_NAME)`, unde PRJ_NAME se afla in ft_project.h

			aceasta am facut pentru a fi mai usor de printat o eroare.

			Deci, avem:
				int			ft_proj_err(const char *msg, int exit_program);
				si mai multe in ft_errors.h

* Pentru a aduaga ceva nou, pur si simplu creati noi foldere, Makefilul va avea grija de tot

* Am in libft t_dict, un echivalent la dictionary ca si in python (sau alte limbaje)
