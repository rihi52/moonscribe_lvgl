#ifndef BUTTON_H
#define BUTTON_H

/*
 * Returns a button styled to be a home screen button.
 * Takes the buttons parent and the button label as arguments
 *  */
lv_obj_t *gpMainButton(lv_obj_t *pParent, const char *pButtonLabel);

/*
 * Returns a button styled to be a Sidebar button.
 * Takes the buttons parent and the button label as arguments
 *  */
lv_obj_t *gpSidebarButton(lv_obj_t *pParent, const char *pButtonLabel);

#endif  /* BUTTON_H */
