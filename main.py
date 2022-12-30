import csv
import folium
import webbrowser


m = folium.Map(
    location=[43.33285, 5.3931],
    tiles="OpenStreetMap",
    zoom_start=100
    )


with open('longlat.txt') as f:
    reader = csv.reader(f, delimiter=',')
    for line in reader:
        folium.Marker(
            location=[
                line[0].strip(),
                line[1].strip()]
            ).add_to(m)


m.save("map.html")
