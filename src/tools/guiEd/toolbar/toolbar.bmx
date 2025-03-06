Strict

Local icons$[] = ["page_white.png", "folder.png", "disk.png", "", "rss.png", "control_stop.png", "text_padding_top.png", "table.png", "textfield.png", "chart_organisation.png", "text_list_bullets.png", "application_split.png", "application_side_expand.png", "tab.png", "text_allcaps.png", "image.png", "textfield_rename.png", "application.png", "", "select.png", "", "box.png", "", "book_open.png", "comment.png"]
Local WIDTH = 16 * icons$.Dimensions()[0]
Local HEIGHT = 16

Local pixmap:TPixmap = CreatePixmap(WIDTH, HEIGHT, PF_RGBA8888)

Local c = 0
For Local icon$ = EachIn icons$
	If icon$ <> ""
		Local iconpng:TPixmap = LoadPixmap(icon$)
		pixmap.Paste iconpng, 16 * c, 0
		iconpng = Null
	End If
	c :+ 1
Next

SavePixmapPNG pixmap, "../toolbar.png", 9