ChestEvent = {}

ChestEvent.new = function(eventName, itemID, itemCount)
	local initChest = function(self)
		self.character = ResourceHelper.getCurrentMap():getEvent(eventName)
		self.opened = false
		self.chestType = 1
		self.animationAtEnd = false
		self.empty = false

		self.itemID = itemID
		self.itemCount = itemCount

		self.update = function()
			if ResourceHelper.getPlayer():inFrontOf(self.character)
			and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				if ResourceHelper.getPlayer():getDirection() == 3 and not self.opened then
					self.opened = true
				end
			end

			if self.animationAtEnd and not self.empty then
				local item = ResourceHelper.getItem(self.itemID)

				drawMessage(_t("Obtained") .. " " .. self.itemCount .. " " .. item:name())

				ResourceHelper.getPlayer():inventory():addItem(self.itemID, self.itemCount, 1)

				self.empty = true
			end

			if self.opened then
				if not self.character:currentAnimation():isFinished() then
					self.character:setCurrentAnimation(self.chestType)
					self.character:setAnimated(true)
				else
					self.animationAtEnd = true
					self.character:setCurrentFrame(self.chestType + 3 * 4)
					self.character:setAnimated(false)
				end
			else
				self.character:setCurrentFrame(self.chestType)
				self.character:setAnimated(false)
			end
		end

		self.render = function()
			self.event:render()
		end

		self.movements = {
			function() end
		}

		return self
	end

	return {initChest = initChest}
end
