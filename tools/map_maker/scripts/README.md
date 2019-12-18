# Updating existing maps

Every maps specifies it bounding box in the xml-element "bounds".
The script `create\_map\_request.pl` parses a map and prints out
a URL for downloading that region again.

For example to use it together with wget, simply do:

    create_map_request.pl map.osm | wget -O new_map_name -i -

Be aware of the trailing '-' (minus) sign at the end of wget's parameters
