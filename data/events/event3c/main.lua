event3c = CharacterEvent.new("event3c", 0, false)

event3c.init = function()
	event3c = event3c:initCharacter();
	
	event3c.addMessages = function()
		local dialog = ActivityManager.newDialog()
		
		dialog:addMessage(_t("event3c-0"))
		
		dialog:addMessage("<Command>" .. _t("event3c-1"))
		dialog:addCommand(_t("Yes"))
		dialog:addCommand(_t("No"))
		
		dialog:addMessage("[0]" .. _t("event3c-2"))
		dialog:addMessage("[1]" .. _t("event3c-3"))
		
		dialog:update();
	end
	
	event3c.movements = {
		function() event3c.character:moveLeft() end,
		function() event3c.character:moveUp() end,
		function() event3c.character:moveRight() end,
		function() event3c.character:moveDown() end
	}
end

