CharacterEvent = {
	new = function(eventName, nbOfMessages)
		local character = MapManager.currentMap:getEvent(eventName)
		
		local render = function(self)
			self.character:render()
		end
		
		local action = function(self)
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				self.character:setDirection(3 - CharacterManager.player():getDirection())
				
				local dialog = ActivityManager.newDialog()
				
				for i = 0, nbOfMessages do
					dialog:addMessage(_t(eventName .. "-" .. tostring(i)))
				end
			end
		end
		
		return {
			character = character,
			render = render,
			action = action,
			movements = movements,
			addMovement = addMovement
		}
	end
}

