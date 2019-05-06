from django.shortcuts import render

# Create your views here.

def bluetooth_view(request, *args, **kwargs):
	return render(request, "connection.html", {})
