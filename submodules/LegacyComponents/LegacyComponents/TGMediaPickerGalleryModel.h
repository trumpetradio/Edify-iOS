#import <LegacyComponents/TGModernGalleryModel.h>

#import <LegacyComponents/TGMediaPickerGalleryInterfaceView.h>
#import <LegacyComponents/TGModernGalleryController.h>

#import <LegacyComponents/TGPhotoEditorController.h>

#import <LegacyComponents/LegacyComponentsContext.h>

@class TGModernGalleryController;
@class TGMediaPickerGallerySelectedItemsModel;
@protocol TGMediaEditAdjustments;

@class TGMediaSelectionContext;
@protocol TGMediaSelectableItem;

@class TGSuggestionContext;

@interface TGMediaPickerGalleryModel : TGModernGalleryModel

@property (nonatomic, copy) void (^willFinishEditingItem)(id<TGMediaEditableItem> item, id<TGMediaEditAdjustments> adjustments, id temporaryRep, bool hasChanges);
@property (nonatomic, copy) void (^didFinishEditingItem)(id<TGMediaEditableItem>item, id<TGMediaEditAdjustments> adjustments, UIImage *resultImage, UIImage *thumbnailImage);
@property (nonatomic, copy) void (^didFinishRenderingFullSizeImage)(id<TGMediaEditableItem> item, UIImage *fullSizeImage);

@property (nonatomic, copy) void (^saveItemCaption)(id<TGMediaEditableItem> item, NSString *caption, NSArray *entities);

@property (nonatomic, copy) void (^storeOriginalImageForItem)(id<TGMediaEditableItem> item, UIImage *originalImage);

@property (nonatomic, copy) id<TGMediaEditAdjustments> (^requestAdjustments)(id<TGMediaEditableItem> item);

@property (nonatomic, copy) void (^editorOpened)(void);
@property (nonatomic, copy) void (^editorClosed)(void);

@property (nonatomic, assign) bool useGalleryImageAsEditableItemImage;
@property (nonatomic, weak) TGModernGalleryController *controller;

@property (nonatomic, assign) bool inhibitMute;

@property (nonatomic, readonly, strong) TGMediaPickerGalleryInterfaceView *interfaceView;
@property (nonatomic, readonly, strong) TGMediaPickerGallerySelectedItemsModel *selectedItemsModel;

@property (nonatomic, copy) NSInteger (^externalSelectionCount)(void);

@property (nonatomic, readonly) TGMediaSelectionContext *selectionContext;
@property (nonatomic, strong) TGSuggestionContext *suggestionContext;

- (instancetype)initWithContext:(id<LegacyComponentsContext>)context items:(NSArray *)items focusItem:(id<TGModernGalleryItem>)focusItem selectionContext:(TGMediaSelectionContext *)selectionContext editingContext:(TGMediaEditingContext *)editingContext hasCaptions:(bool)hasCaptions allowCaptionEntities:(bool)allowCaptionEntities hasTimer:(bool)hasTimer onlyCrop:(bool)onlyCrop inhibitDocumentCaptions:(bool)inhibitDocumentCaptions hasSelectionPanel:(bool)hasSelectionPanel hasCamera:(bool)hasCamera recipientName:(NSString *)recipientName;

@end
