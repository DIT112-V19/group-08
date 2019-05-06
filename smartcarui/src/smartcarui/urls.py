# Simply declaring to which URL path the user will go to depending on the folder selected
# Rendering a view depending on the path

from django.contrib import admin
from django.urls import path

from bluetoothconnection.views import bluetooth_view
from ui.views import ui_view

urlpatterns = [
    path('admin/', admin.site.urls),
    path('bluetooth/', bluetooth_view),
    path('', ui_view)
]
