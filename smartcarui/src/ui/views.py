from django.shortcuts import render

# Create your views here.

def ui_view(request, *args, **kwargs):
	return render(request, "index.html", {})