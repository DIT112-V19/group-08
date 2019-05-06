First setup for Linux/Mac:

DELETE the folder env (Which is the environment I created on my computer)

Open a terminal in this folder and type the following commands

	virtualenv <env_name> //Create environment for separate libraries 
	source env/bin/activate //Activate environment
	pip install django //INstall Django in the virtual environment
	django-admin startproject <project_name> //create project in Django
	cd src
	python manage.py runserver //Run the Django server