     ___       _______  ____    ____  ___      .__   __.   ______  _______  _______
    /   \     |       \ \   \  /   / /   \     |  \ |  |  /      ||   ____||       \
   /  ^  \    |  .--.  | \   \/   / /  ^  \    |   \|  | |  ,----'|  |__   |  .--.  |
  /  /_\  \   |  |  |  |  \      / /  /_\  \   |  . `  | |  |     |   __|  |  |  |  |
 /  _____  \  |  '--'  |   \    / /  _____  \  |  |\   | |  `----.|  |____ |  '--'  |
/__/     \__\ |_______/     \__/ /__/     \__\ |__| \__|  \______||_______||_______/

             _______ .__   __. .___________. __  .___________.____    ____
            |   ____||  \ |  | |           ||  | |           |\   \  /   /
            |  |__   |   \|  | `---|  |----`|  | `---|  |----` \   \/   /
            |   __|  |  . `  |     |  |     |  |     |  |       \_    _/
            |  |____ |  |\   |     |  |     |  |     |  |         |  |
            |_______||__| \__|     |__|     |__|     |__|         |__|

         .___________.  ______    __  ___  _______ .__   __.      _______.
         |           | /  __  \  |  |/  / |   ____||  \ |  |     /       |
         `---|  |----`|  |  |  | |  '  /  |  |__   |   \|  |    |   (----`
             |  |     |  |  |  | |    <   |   __|  |  . `  |     \   \
             |  |     |  `--'  | |  .  \  |  |____ |  |\   | .----)   |
             |__|      \______/  |__|\__\ |_______||__| \__| |_______/

CONTENTS OF THIS FILE
--------------------------------------------------------------------------------

  * Introduction
  * AET Insert
  * Installing

--------------------------------------------------------------------------------
INTRODUCTION
--------------------------------------------------------------------------------

Current Maintainer: Eyal Shalev <eyalsh@gmail.com>

Advanced Entity Tokens (AET) reveals all of Drupal's entities to the token
system by using their entity_id.

This module depends on both the entity_token & token modules.

An example use case of what the module can provide is using taxonomy to manage
your images and then using AET & token_filter to print it in varius text fields.

--------------------------------------------------------------------------------
AET Insert
--------------------------------------------------------------------------------

AET Insert is a UI tool built to allow content managers to use AET tokens.

After enabling the module you will need to navigate to any text field edit page
and click the AET Insert checkbox.

The AET Insert field adds a very simple filtering for AET.

--------------------------------------------------------------------------------
Installing
--------------------------------------------------------------------------------

1. Unpack this module in your modules folder.
3. Enable the AET module in your Drupal site.
4. Enter one of the above examples in a Token supported field (I suggest
   installing token_filter to enable token filtering in general text fields).
