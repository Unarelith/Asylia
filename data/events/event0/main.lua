event0 = CharacterEvent.new("event0")

event0.init = function()
	event0 = event0:initCharacter()
	
	--event0.character:addAction('ActivityManager.drawMessage("a")');
	--event0.character:addAction('ActivityManager.drawMessage("b")');
	
	local px = CharacterManager.player():x()
	local py = CharacterManager.player():y()
	
	event0.update = function()
		if CharacterManager.player():inFrontOf(event0.character) then
			event0.character:startActions()
		end
	end
	
	event0.actions = {
		function() ActivityManager.drawMessage("a") end,
		function() ActivityManager.drawMessage("b"); end
	}
	
	event0.updateActions()
	
	event0.movements = {
		function() event0.character:moveLeft() end,
		function() event0.character:moveUp() end,
		function() event0.character:moveRight() end,
		function() event0.character:moveDown() end
	}
end

