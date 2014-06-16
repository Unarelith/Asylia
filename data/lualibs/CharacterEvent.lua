CharacterEvent = {
	new = function(eventName)
		local initCharacter = function(self)
			self.character = MapManager.currentMap:getEvent(eventName)
			
			self.update = function() end
			
			self.render = function()
				self.character:render()
			end
			
			self.actions = {}
			
			self.updateActions = function()
				for i=1, #self.actions do
					local func = string.dump(self.actions[i])
					event0.character:addAction(func)
				end
			end
			
			return self
		end
		
		return {initCharacter = initCharacter}
	end
}

