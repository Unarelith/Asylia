event3c = CharacterEvent.new("event3c", 0, false)

event3c.init = function()
	event3c = event3c:initCharacter();
	
	event3c.addMessages = function()
		local dialog = ActivityManager.newDialog()
		
		dialog:addMessage(_t("event3c-0"))
		
		dialog:addMessage("<Command>Would you know that?")
		dialog:addCommand("Yes")
		dialog:addCommand("No")
		
		dialog:addMessage("[0]Haha you'll never know.")
		dialog:addMessage("[1]Come back later.")
	end
	
	event3c.movements = {
		function() event3c.character:moveLeft() end,
		function() event3c.character:moveUp() end,
		function() event3c.character:moveRight() end,
		function() event3c.character:moveDown() end
	}
end

