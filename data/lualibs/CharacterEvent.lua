CharacterEvent = {}

CharacterEvent.new = function(eventName)
	local initCharacter = function(self)
		self.character = MapManager.currentMap:getEvent(eventName)
		
		self.update = function() end
		
		self.render = function()
			self.character:render()
		end
		
		self.actions = {}
		self.currentActionID = 0
		
		self.action = function()
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				self.character:setDirection(3 - CharacterManager.player():getDirection())
				
				self.render() -- Update the Character direction in screenshot
				
				if self.currentActionID < #self.actions then
					if self.actions[self.currentActionID]() then
						self.currentActionID = self.currentActionID + 1;
					end
				end
			end
		end
		
		self.collisionAction = function() end
		
		return self
	end
	
	return {initCharacter = initCharacter}
end

