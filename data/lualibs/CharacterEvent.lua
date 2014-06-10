CharacterEvent = {}

CharacterEvent.new = function(eventName, nbOfMessages)
	local initCharacter = function(self)
		self.character = MapManager.currentMap:getEvent(eventName)
		
		self.update = function() end
		
		self.render = function()
			self.character:render()
		end
		
		self.action = function()
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				self.character:setDirection(3 - CharacterManager.player():getDirection())
				
				self.render() -- Update the Character direction in screenshot
				
				local dialog = ActivityManager.newDialog()
				
				for i = 0, nbOfMessages - 1 do
					dialog:addMessage(_t(eventName .. "-" .. tostring(i)))
				end
			end
		end
		
		self.collisionAction = function() end
		
		return self
	end
	
	return {initCharacter = initCharacter}
end

